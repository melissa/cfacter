/**
 * @file
 * Declares utility functions for enumerating directories.
 */
#ifndef FACTER_UTIL_DIRECTORY_HPP_
#define FACTER_UTIL_DIRECTORY_HPP_

#include <string>
#include <functional>

namespace facter { namespace util {

    /**
     * Contains utility functions for enumerating directories.
     */
    struct directory
    {
        /**
         * Enumerates the files that match the given pattern in the given directory.
         * @param path The directory path to search for the files.
         * @param callback The callback to invoke when a matching file is found.
         * @param pattern The pattern to filter the file names by.  If empty, all files are passed.
         */
        static void each_file(std::string const& path, std::function<bool(std::string const&)> callback, std::string const& pattern = {});

        /**
         * Enumerates the subdirectories in the given directory.
         * @param path The directory path to search for the subdirectories.
         * @param callback The callback to invoke when a matching subdirectory is found.
         * @param pattern The pattern to filter the subdirectory names by.  If empty, all subdirectories are passed.
         */
        static void each_subdirectory(std::string const& path, std::function<bool(std::string const&)> callback, std::string const& pattern = {});
    };

}}  // namespace facter::util

#endif  // FACTER_UTIL_DIRECTORY_HPP_