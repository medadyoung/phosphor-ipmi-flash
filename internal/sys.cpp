/*
 * Copyright 2018 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "sys.hpp"

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

namespace blobs
{
namespace flash
{
namespace internal
{

int SysImpl::open(const char* pathname, int flags) const
{
    return ::open(pathname, flags);
}

int SysImpl::close(int fd) const
{
    return ::close(fd);
}

void* SysImpl::mmap(void* addr, size_t length, int prot, int flags, int fd,
                    off_t offset) const
{
    return ::mmap(addr, length, prot, flags, fd, offset);
}

int SysImpl::munmap(void* addr, size_t length) const
{
    return ::munmap(addr, length);
}

int SysImpl::getpagesize() const
{
    return ::getpagesize();
}

SysImpl sys_impl;

} // namespace internal
} // namespace flash
} // namespace blobs
