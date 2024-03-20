# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/_deps/ds-src"
  "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/_deps/ds-build"
  "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/_deps/ds-subbuild/ds-populate-prefix"
  "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/_deps/ds-subbuild/ds-populate-prefix/tmp"
  "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/_deps/ds-subbuild/ds-populate-prefix/src/ds-populate-stamp"
  "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/_deps/ds-subbuild/ds-populate-prefix/src"
  "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/_deps/ds-subbuild/ds-populate-prefix/src/ds-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/_deps/ds-subbuild/ds-populate-prefix/src/ds-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/_deps/ds-subbuild/ds-populate-prefix/src/ds-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
