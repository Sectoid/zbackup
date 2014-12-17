// Copyright (c) 2012-2014 Konstantin Isakov <ikm@zbackup.org> and ZBackup contributors, see CONTRIBUTORS
// Part of ZBackup. Licensed under GNU GPLv2 or later + OpenSSL, see LICENSE

#ifndef RANDOM_HH_INCLUDED__
#define RANDOM_HH_INCLUDED__

#include <zbackup/exception.hh>

namespace Random {
ZBACKUP_DEF_EX( exCantGenerate, "Error generating random sequence, try later", std::exception )

/// This one fills the buffer with true randomness, suitable for a key
void generateTrue( void * buf, unsigned size );
/// This one fills the buffer with pseudo randomness, suitable for salts but not
/// keys
void generatePseudo( void * buf, unsigned size );
}

#endif
