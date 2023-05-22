# Changelog

> All notable changes to this project will be documented in this file.</br>
> The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/), </br>
> and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).</br>
> To add a tag to the git repository do:
>
> > git tag -a v1.0.9 -m "removed unecessary code"</br>
> > git push origin v1.0.9

IMPORTANT:

- Manually keep the changelog version number in sync with CMakeLists.txt project version<br>
- Keep the changelog.md up to date, neat and tidy, (as it is a convenient tool for code maintenance).<br>
- Use [Semantic Versioning](https://semver.org/spec/v2.0.0.html) such that<br>
- Given a version number MAJOR.MINOR.PATCH, increment the:<br>
- MAJOR version when you make incompatible API changes,<br>
- MINOR version when you add functionality in a backwards compatible manner, and<br>
- PATCH version when you make backwards compatible bug fixes. <br>
- But there is no need to change the version number for correcting spelling errors, (etc).<br>
- MAKE SURE to tag and update the tag compare list below, (for quick code comparison purposes).<br>

## [Unreleased]

Detailed test cases</br>
Detailed class descriptions in README.md</br>
Correct URL for github, (for source compare)</br>

## [Next Steps]

Adding dock test cases </br>
Adding unit test cases </br>
Updated README.md accordingly</br>

#### 1.0.9 (2023-05-22)
### Changed
- removed unecessary code

#### 1.0.6 (2023-05-22)
### Changed
- relocated interfaces/

#### 1.0.5 (2023-05-22)
### Changed
- relocated interfaces/

#### 1.0.4 (2023-05-22)
### Changed
- refactored injections/interface.hpp

#### 1.0.0 (2023-05-21)
### Changed
- refactored project name to injections

#### 0.2.1 (2023-05-21)
### Changed
- injections created from template

#### 0.1.0 (2021-09-03)
### Added
- SHARED library support
- (perriera) extras library support 
- CPM.cmake support
  - [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake/blob/master/LICENSE)
  - This allows us to include other Github packages with the ability
    to add package OPTIONS
- FakeIt Mock Library support
  - [FakeIt](https://github.com/eranpeer/FakeIt)
  - This gives us the ability to mock C++ interfaces, (before implementation)
- Catch2 support
  - [Catch2](https://github.com/catchorg/Catch2)
  - This gives us the ability to test C++ classes, (during implementation)

### Changed

- CMakeLists.txt
  - [ModernCppStarter](https://github.com/TheLartians/ModernCppStarter/blob/master/LICENSE)
- spdlog is now used as a shared library, (libspdlog.so)
- cpr is now used as a shared library, (libcpr.so)
- placed all source into /src
- placed all headers into /include/injections

#### 0.1.0 (2021-08-26)

### Added

- Fetch_Content support
- changelog.md
- Project VERSION inside CMakeLists.txt & changelog.md
- Adopted new changelog format.
- sudo make install parameters
- shared library support
- sudo checkinstall support
- GoF: Abstract design pattern support
- Debian package support
- extra/interfaces.hpp support
- Unit test casses support, (Catch2)
- Mock framework support, (FakeIt)

### Changed

- CMakeLists.txt revamped & streamlined
- README.md revamped & streamlined
- Added documentation on code
- cxx_std_17 on all targets
- std::filesystem on all targets

### Maintained

- @brief style formatting
- Doxygen support

### Removed

- Conan package manager deprecated

### Note
> The following will only show on PUBLIC repositories:
[unreleased]: https://github.com/perriera/injections/compare/v1.0.9...HEAD
[1.0.9]: https://github.com/perriera/injections/compare/v1.0.7...v1.0.9
[1.0.7]: https://github.com/perriera/injections/compare/v1.0.6...v1.0.7
[1.0.6]: https://github.com/perriera/injections/compare/v1.0.5...v1.0.6
[1.0.5]: https://github.com/perriera/injections/compare/v1.0.4...v1.0.5
[1.0.4]: https://github.com/perriera/injections/compare/v1.0.0...v1.0.4
[1.0.0]: https://github.com/perriera/injections/compare/v0.2.1...v1.0.0
[0.2.1]: https://github.com/perriera/injections/compare/v0.1.0...v0.2.1
[0.1.0]: https://github.com/perriera/injections/compare/v0.0.0...v0.1.0
[0.0.0]: https://github.com/perriera/injections/tree/v0.0.0
