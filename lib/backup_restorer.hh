// Copyright (c) 2012-2014 Konstantin Isakov <ikm@zbackup.org> and ZBackup contributors, see CONTRIBUTORS
// Part of ZBackup. Licensed under GNU GPLv2 or later + OpenSSL, see LICENSE

#ifndef BACKUP_RESTORER_HH_INCLUDED__
#define BACKUP_RESTORER_HH_INCLUDED__

#include <stddef.h>
#include <exception>
#include <string>
#include <set>

#include <zbackup/exception.hh>

#include "chunk_storage.hh"

/// Generic interface to stream data out
class DataSink
{
public:
  virtual void saveData( void const * data, size_t size )=0;
  virtual ~DataSink() {}
};

/// Restores the backup
namespace BackupRestorer {

ZBACKUP_DEF_EX( Ex, "Backup restorer exception", std::exception )
ZBACKUP_DEF_EX( exTooManyBytesToEmit, "A backup record asks to emit too many bytes", Ex )

typedef std::set< ChunkId > ChunkSet;

/// Restores the given backup
void restore( ChunkStorage::Reader &, std::string const & backupData,
              DataSink *, ChunkSet * );

/// Performs restore iterations on backupData
void restoreIterations( ChunkStorage::Reader &, BackupInfo &, std::string &, ChunkSet * );
}

#endif
