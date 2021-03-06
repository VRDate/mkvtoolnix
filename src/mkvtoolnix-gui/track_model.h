#ifndef MTX_MKVTOOLNIXGUI_TRACK_MODEL_H
#define MTX_MKVTOOLNIXGUI_TRACK_MODEL_H

#include "common/common_pch.h"

#include "mkvtoolnix-gui/source_file.h"

#include <QAbstractItemModel>
#include <QIcon>
#include <QList>

class TrackModel;
typedef std::shared_ptr<TrackModel> TrackModelPtr;

class TrackModel : public QAbstractItemModel {
  Q_OBJECT;

protected:
  static int const CodecColumn      = 0;
  static int const TypeColumn       = 1;
  static int const MuxColumn        = 2;
  static int const LanguageColumn   = 3;
  static int const IDColumn         = 4;
  static int const NameColumn       = 5;
  static int const SourceFileColumn = 6;
  static int const NumberOfColumns  = 7;

  QList<Track *> *m_tracks;
  QIcon m_audioIcon, m_videoIcon, m_subtitleIcon, m_attachmentIcon, m_chaptersIcon, m_tagsIcon, m_genericIcon, m_yesIcon, m_noIcon;

  debugging_option_c m_debug;

public:
  TrackModel(QObject *parent);
  virtual ~TrackModel();

  virtual void setTracks(QList<Track *> &tracks);
  virtual void addTracks(QList<TrackPtr> tracks);
  virtual void clear();

  virtual QModelIndex index(int row, int column, QModelIndex const &parent) const;
  virtual QModelIndex parent(QModelIndex const &child) const;

  virtual int rowCount(QModelIndex const &parent) const;
  virtual int columnCount(QModelIndex const &parent) const;

  virtual QVariant data(QModelIndex const &index, int role) const;
  virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

  virtual void trackUpdated(Track *track);

protected:
  Track *trackFromIndex(QModelIndex const &index) const;

  QVariant dataDecoration(QModelIndex const &index, Track *track) const;
  QVariant dataDisplay(QModelIndex const &index, Track *track) const;
  QVariant dataTextAlignment(QModelIndex const &index) const;

  static int rowForTrack(QList<Track *> const &tracks, Track *trackToLookFor);
};

#endif  // MTX_MKVTOOLNIXGUI_TRACK_MODEL_H
