#ifndef OPENMC_ERROR_H
#define OPENMC_ERROR_H

#include <cstring>
#include <string>
#include <sstream>

#include "openmc/capi.h"

namespace openmc {

inline void
set_errmsg(const char* message)
{
  std::strcpy(openmc_err_msg, message);
}

inline void
set_errmsg(const std::string& message)
{
  std::strcpy(openmc_err_msg, message.c_str());
}

inline void
set_errmsg(const std::stringstream& message)
{
  std::strcpy(openmc_err_msg, message.str().c_str());
}

[[noreturn]] void fatal_error(const std::string& message, int err=-1);

inline
void fatal_error(const std::stringstream& message)
{
  fatal_error(message.str());
}

inline
void fatal_error(const char* message)
{
  fatal_error({message, std::strlen(message)});
}

void warning(const std::string& message);

inline
void warning(const std::stringstream& message)
{
  warning(message.str());
}

void write_message(const std::string& message, int level);

inline
void write_message(const std::stringstream& message, int level)
{
  write_message(message.str(), level);
}

#ifdef OPENMC_MPI
extern "C" void abort_mpi(int code);
#endif

} // namespace openmc
#endif // OPENMC_ERROR_H