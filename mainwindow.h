/***************************************************************************
 *   Copyright (C) 2012 by Christian Doerffel                              *
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

#ifndef _MainWindow_H
#define _MainWindow_H

#include <QtGui/QMainWindow>
#include <QSignalMapper>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT
protected:
  Ui::MainWindow ui;
  QSignalMapper mapper;
  
public:
  MainWindow(QWidget *parent = 0);
  void fillTreeWidget(int);

public slots:
  void selectFolder(int);
  void compareFiles();
  void changeTrashDirectory();
};

#endif
