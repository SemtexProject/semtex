# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/duck/Documents/projects/mouse/bin/_deps/spdlog-src"
  "/Users/duck/Documents/projects/mouse/bin/_deps/spdlog-build"
  "/Users/duck/Documents/projects/mouse/bin/_deps/spdlog-subbuild/spdlog-populate-prefix"
  "/Users/duck/Documents/projects/mouse/bin/_deps/spdlog-subbuild/spdlog-populate-prefix/tmp"
  "/Users/duck/Documents/projects/mouse/bin/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp"
  "/Users/duck/Documents/projects/mouse/bin/_deps/spdlog-subbuild/spdlog-populate-prefix/src"
  "/Users/duck/Documents/projects/mouse/bin/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/duck/Documents/projects/mouse/bin/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/duck/Documents/projects/mouse/bin/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
