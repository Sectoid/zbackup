// Copyright (c) 2012-2014 Konstantin Isakov <ikm@zbackup.org> and ZBackup contributors, see CONTRIBUTORS
// Part of ZBackup. Licensed under GNU GPLv2 or later + OpenSSL, see LICENSE

#ifndef ZBACKUP_BASE_HH_INCLUDED__
#define ZBACKUP_BASE_HH_INCLUDED__

#include <exception>
#include <string>

#include <zbackup/exception.hh>

#include "chunk_index.hh"

struct Paths
{
  std::string storageDir;

  Paths( std::string const & storageDir );

  std::string getTmpPath();
  std::string getRestorePath();
  std::string getCreatePath();
  std::string getBundlesPath();
  std::string getStorageInfoPath();
  std::string getIndexPath();
  std::string getBackupsPath();
};

class ZBackupBase: public Paths
{
public:
  ZBACKUP_DEF_EX( Ex, "ZBackup exception", std::exception )
  ZBACKUP_DEF_EX_STR( exWontOverwrite, "Won't overwrite existing file", Ex )
  ZBACKUP_DEF_EX( exStdinError, "Error reading from standard input", Ex )
  ZBACKUP_DEF_EX( exWontReadFromTerminal, "Won't read data from a terminal", exStdinError )
  ZBACKUP_DEF_EX( exStdoutError, "Error writing to standard output", Ex )
  ZBACKUP_DEF_EX( exWontWriteToTerminal, "Won't write data to a terminal", exStdoutError )
  ZBACKUP_DEF_EX( exSerializeError, "Failed to serialize data", Ex )
  ZBACKUP_DEF_EX( exParseError, "Failed to parse data", Ex )
  ZBACKUP_DEF_EX( exChecksumError, "Checksum error", Ex )
  ZBACKUP_DEF_EX_STR( exCantDeriveStorageDir, "The path must be within the backups/ dir:", Ex )

  /// Opens the storage
  ZBackupBase( std::string const & storageDir, std::string const & password );
  ZBackupBase( std::string const & storageDir, std::string const & password, bool prohibitChunkIndexLoading );

  /// Creates new storage
  static void initStorage( std::string const & storageDir, std::string const & password,
                           bool isEncrypted );

  /// For a given file within the backups/ dir in the storage, returns its
  /// storage dir or throws an exception
  static std::string deriveStorageDirFromBackupsFile( std::string const & backupsFile, bool allowOutside = false );

  void useDefaultCompressionMethod();

  void setPassword( std::string const & password );

  StorageInfo storageInfo;
  EncryptionKey encryptionkey;
  TmpMgr tmpMgr;
  ChunkIndex chunkIndex;

private:
  StorageInfo loadStorageInfo();
};


#endif
