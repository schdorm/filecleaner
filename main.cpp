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
#include <QtGui/QMessageBox>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
  QApplication app(argc,argv);
  
  qWarning () << QDir::home().absolutePath() + "/.fileCleaner";
  
  MainWindow mw;
  mw.show();
  
  QFile info(QDir::home().absolutePath() + "/.fileCleaner");
  if(!info.exists())
  {
    QMessageBox::warning(&mw, "Take care!", "Be careful when using this application. It can destroy a lot of data in a few seconds!");
    info.open(QIODevice::WriteOnly);
//     info.write(" ");
    info.close();
  }
  return app.exec();
}
