//
//  FileManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 19/01/2022.
//

#include "FileManager.hpp"

namespace grumble {
FileManager::FileManager(FileManagerConfiguration configuration)
    : _configuration(configuration) {}

FileManager::~FileManager() {}

std::string FileManager::loadFile(std::filesystem::path filename) {
  std::filesystem::path path = buildReadPath(filename);
  if (!std::filesystem::exists(path)) {
    logError("File at path " + path.string() + " doesn't exist.");
    return "";
  }

  // std::ifstream file(path);
  // std::string str((std::istreambuf_iterator<char>(file)),
  // std::istreambuf_iterator<char>());
  return "";
}

std::vector<char> FileManager::loadFileRaw(std::filesystem::path filename) {
  std::filesystem::path path = buildReadPath(filename);
  if (!std::filesystem::exists(path)) {
    logError("File at path " + path.string() + " doesn't exist.");
    return std::vector<char>();
  }

  // std::ifstream file(path, std::ios_base::binary);
  // std::vector<char> buffer((std::istreambuf_iterator<char>(file)),
  // std::istreambuf_iterator<char>());
  return std::vector<char>();
}

ImageFile::unique_ptr FileManager::loadPNG(std::filesystem::path filename) {
  logInfo("Attempting to load png image: " + filename.string());

  std::filesystem::path path = buildReadPath(filename);
  if (!std::filesystem::exists(path)) {
    logError("File at path " + path.string() + " doesn't exist.");
    return nullptr;
  }

  FILE *fp = fopen(path.c_str(), "rb");
  if (fp == nullptr) {
    logError("Unable to open path for png reading to {}", path.string());
    return nullptr;
  }

  png_structp pngPtr =
      png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, FileManager::pngError,
                             FileManager::pngWarning);
  if (!pngPtr) {
    logError("Couldn't initialise png read struct");
    fclose(fp);
    return nullptr;
  }

  png_infop infoPtr = png_create_info_struct(pngPtr);
  if (!infoPtr) {
    logError("Couldn't initialise png info struct");
    png_destroy_read_struct(&pngPtr, (png_infopp)0, (png_infopp)0);
    fclose(fp);
    return nullptr;
  }

  png_init_io(pngPtr, fp);
  png_read_info(pngPtr, infoPtr);

  png_uint_32 imgWidth = png_get_image_width(pngPtr, infoPtr);
  png_uint_32 imgHeight = png_get_image_height(pngPtr, infoPtr);
  //    png_uint_32 bitDepth = png_get_bit_depth(pngPtr, infoPtr);
  //    png_uint_32 channels = png_get_channels(pngPtr, infoPtr);
  //    png_uint_32 color_type = png_get_color_type(pngPtr, infoPtr);

  //    logInfo("Image Size: " + std::to_string(imgWidth) + ", " +
  //    std::to_string(imgHeight)); logInfo("bitDepth: " +
  //    std::to_string(bitDepth)); logInfo("channels: " +
  //    std::to_string(channels)); logInfo("color_type: " +
  //    std::to_string(color_type));

  size_t rowSize = png_get_rowbytes(pngPtr, infoPtr);
  auto arrayLength = imgHeight * rowSize;

  // TODO: Not sure if we need to delete this as we're creating
  // a smart pointer from it. Something to look into
  png_byte *rowPtrs = new png_byte[arrayLength];

  for (int i = 0; i < imgHeight; i++) {
    long index = (arrayLength - rowSize) - rowSize * i;
    png_read_row(pngPtr, &rowPtrs[index], NULL);
  }
  png_read_end(pngPtr, infoPtr);

  fclose(fp);
  png_destroy_read_struct(&pngPtr, &infoPtr, NULL);
  return std::make_unique<ImageFile>(imgWidth, imgHeight, rowSize,
                                     std::shared_ptr<unsigned char>(rowPtrs));
}

void FileManager::writePNG(std::filesystem::path filename,
                           ImageFile::unique_ptr file) {
  std::filesystem::path path = buildWritePath(filename);
  FILE *fp = fopen(path.c_str(), "wb");
  if (fp == nullptr) {
    logError("Unable to open path for png writing to {}", path.string());
    return;
  }

  png_structp pngPtr =
      png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!pngPtr) {
    logError("Couldn't initialise png read struct");
    fclose(fp);
    return;
  }

  png_infop infoPtr = png_create_info_struct(pngPtr);
  if (!infoPtr) {
    logError("Couldn't initialise png info struct");
    png_destroy_read_struct(&pngPtr, (png_infopp)0, (png_infopp)0);
    fclose(fp);
    return;
  }

  png_init_io(pngPtr, fp);

  // Output is 8bit depth, RGBA format.
  png_set_IHDR(pngPtr, infoPtr, file->width(), file->height(), 8,
               PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE,
               PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
  png_write_info(pngPtr, infoPtr);

  png_bytep *rows = new png_bytep[file->height()];
  for (int i = 0; i < file->height(); i++) {
    rows[i] = new png_byte[file->bytesPerRow()];
  }
  png_write_image(pngPtr, rows);
  png_write_end(pngPtr, NULL);

  fclose(fp);

  png_destroy_write_struct(&pngPtr, &infoPtr);

  for (int i = 0; i < file->height(); i++) {
    delete[] rows[i];
  }
  delete[] rows;
}

void FileManager::pngError(png_structp png_ptr, png_const_charp error_msg) {
  Logger::log("PNG load Error: " + std::string(error_msg), LogLevel::error,
              LogCategory::io);
}

void FileManager::pngWarning(png_structp png_ptr, png_const_charp warning_msg) {
  Logger::log("PNG load Warning: " + std::string(warning_msg), LogLevel::warn,
              LogCategory::io);
}

nlohmann::json FileManager::loadJson(std::filesystem::path filename) {
  std::string raw = loadFile(filename);
  return nlohmann::json::parse(raw);
}

std::filesystem::path
FileManager::buildReadPath(std::filesystem::path filename) {
  return _configuration.rootReadPath / filename;
}

std::filesystem::path
FileManager::buildWritePath(std::filesystem::path filename) {
  return _configuration.rootWritePath / filename;
}

LogCategory FileManager::logCategory() const { return LogCategory::io; }
} // namespace grumble
