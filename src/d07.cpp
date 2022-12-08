#include "utils.hpp"
#include <cstddef>
#include <cstdint>
#include <numeric>
#include <string>
#include <vector>

namespace d07 {
struct File {
  std::string name;
  uint32_t size;
};

struct Directory {
  std::string name;
  Directory *parent;
  std::vector<Directory> subdirectories;
  std::vector<File> files;
};

Directory parse_history(std::vector<std::string> cmds) {
  Directory root = {"/", nullptr, {}, {}};
  root.parent = &root;
  Directory *current_directory = &root;

  for (const auto cmd : cmds) {
    auto tokens = utils::split(cmd, ' ');
    if (tokens.at(0) == "$") {
      if (tokens.at(1) == "cd") {
        if (tokens.at(2) == "..") {
          current_directory = current_directory->parent;
        } else if (tokens.at(2) == "/") {
          current_directory = &root;
        } else {
          for (auto &subdirectory : current_directory->subdirectories) {
            if (subdirectory.name == tokens.at(2)) {
              current_directory = &subdirectory;
              break;
            }
          }
        }
      }
    }

    else if (tokens.at(0) == "dir") {
      Directory new_directory = {tokens.at(1), current_directory, {}, {}};
      current_directory->subdirectories.push_back(new_directory);
    } else {
      uint32_t file_size = utils::to_uint32(tokens.at(0));
      File new_file = {tokens.at(1), file_size};
      current_directory->files.push_back(new_file);
    }
  }

  return root;
}

uint32_t fold_directories(const Directory &dir, uint32_t &acc) {
  uint32_t this_dir_size = 0;

  this_dir_size += std::accumulate(
      dir.files.begin(), dir.files.end(), 0,
      [](auto a, const auto &f) { return a += f.size; });

  this_dir_size += std::accumulate(
      dir.subdirectories.begin(), dir.subdirectories.end(), 0,
      [&acc](auto a, const auto &d) { return a += fold_directories(d, acc); });

  // conditionally tally
  if (this_dir_size < 100000) {
    acc += this_dir_size;
  }

  return this_dir_size;
}

const uint32_t part_one(std::vector<std::string> cmds) {
  auto root = parse_history(cmds);
  uint32_t acc = 0;
  fold_directories(root, acc);

  return acc;
}

// TODO
uint32_t aproximate_directories_part_two(const Directory &dir, uint32_t &approx) {
  uint32_t this_dir_size = 0;

  this_dir_size += std::accumulate(
      dir.files.begin(), dir.files.end(), 0,
      [](auto a, const auto &f) { return a += f.size; });

  this_dir_size += std::accumulate(
      dir.subdirectories.begin(), dir.subdirectories.end(), 0,
      [&approx](auto a, const auto &d) { return a += fold_directories(d, approx); });

  // conditionally tally
  if (this_dir_size < 100000) {
    approx += this_dir_size;
  }

  return this_dir_size;
}



const uint32_t part_two(std::vector<std::string> cmds) {
  auto root = parse_history(cmds);
  auto total_space = 70000000;
  auto needed_space = 30000000;

}
} // namespace d07
