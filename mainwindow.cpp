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

#include "mainwindow.h"
#include <QtGui/QFileDialog>

#include <QtGui/QLabel>

const int sourceID = 1;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), mapper(this)
{
  ui.setupUi(this);
  
  mapper.setMapping(ui.selectDirectoryButton_1, sourceID);
  mapper.setMapping(ui.selectDirectoryButton_2, 2);
  
  connect(ui.selectDirectoryButton_1, SIGNAL(clicked()), &mapper, SLOT(map()));
  connect(ui.selectDirectoryButton_2, SIGNAL(clicked()), &mapper, SLOT(map()));
  connect(&mapper, SIGNAL(mapped(int)), this, SLOT(selectFolder(int)));
//   selectFolder(1);
  
//   connect(ui.selectDirectoryButton_2, SIGNAL(clicked()), this, SLOT(selectFolder()));
}


void MainWindow::selectFolder(int i)
{
  QLabel *label;
  if(i == sourceID)
  {
    label = ui.directoryLabel_1;
  }
  else
    label = ui.directoryLabel_2;  
  label->setText(QFileDialog::getExistingDirectory());
}
