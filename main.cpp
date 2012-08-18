/***************************************************************************
 *   Copyright (C) 2009 - 2012 by Christian Doerffel                       *
 *   schdorm@googlemail.com                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <QtGui/QApplication>
#include <QtDebug>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QFileInfo>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
  QApplication app(argc,argv);
  
  MainWindow mw;
  mw.show();
  // QString command = "cd " + app.arguments().at(1) + "; ls; pwd >> /tmp/md5sums; md5sum * >> /tmp/md5sums";
  // if(!system(command.toUtf8().data()))
  // {/*
  // qWarning() << "Worked!";
  // }*/
  
  // QStringList files = QDir(argv[1]).entryList(QDir::Files);
  // qWarning() << QDir::current().entryList(QDir::Files);
  // QString it; QFile file; 
  // unsigned int hashSum;
  // foreach(it, files)
  // {
    // file.setFileName(it);
  // file.open(QIODevice::ReadOnly);
  // hashSum = qHash(file.readAll());
  // file.close();
  // }
  // QByteArray bf; QString prefix;
  // QFile file("/tmp/md5sums");
  // file.open(QIODevice::ReadOnly);
  // 
  // quint64 key;
  // // bool ok;
  // 
  // QHash<quint64, QString> fileHash;
  // 
  // QHash<quint64, QString> redunFileHash;
  // 
  // while(!file.atEnd())
  // {
    // 	bf = file.readLine();
  // 	if(bf.startsWith("/"))
  // 	{
    // 		prefix = bf.trimmed();
  // 		if(!prefix.endsWith("/"))
  // 			prefix.append("/");
  // 	}
  // 	else
  // 	{
    // // 		key= bf.left(32).toULongLong(&ok, 16); // md5sum
  // // 		QByteArray test = bf; //test.prepend("0x");
  // 		key = hexToDec((bf.trimmed().left(32)));
  // 		qWarning() << key << bf.trimmed().left(32);
  // // 		qWarning() << test.left(32) << hexToDec((test.trimmed().left(32)));
  // // 		if(!ok)
  // // 			qWarning() << "something went wrong!" << bf.left(32) << bf.trimmed().left(32).toULongLong(&ok, 16);
  // 		bf.remove(0,33);			// rest is filename
  // 		if(!fileHash.contains(key))
  // 			fileHash.insert(key, prefix + bf.trimmed());
  // 		else 
  // 		{
    // 			QFileInfo hashedFile(fileHash.value(key));
  // 			QFileInfo newFile(bf.trimmed());
  // 			if(hashedFile.size() == newFile.size())
  // 			{
    // 				if(hashedFile.absolutePath() != newFile.absolutePath())
  // 				{
    // 					redunFileHash.insertMulti(key, bf.trimmed());
  // 					redunFileHash.insertMulti(key, fileHash.take(key));
  // 				}
  // 				else
  // 				qWarning() << "Multiple File Entry!";
  // 			}
  // 			else
  // 				fileHash.insertMulti(key, bf.trimmed());
  // 		}
  // 	}
  // }
  // qWarning() << fileHash;
  // 
  // qWarning() << redunFileHash;
  
  // app.exec();
  return app.exec();
}
