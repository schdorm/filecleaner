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
#include <QtGui/QMessageBox>
#include <QtGui/QLabel>

#include "compare.h"
#include <QtDebug>

const int sourceID = 1;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), mapper(this)
{
  ui.setupUi(this);
  ui.actionQuit->setShortcut(QKeySequence::Quit);
  
  mapper.setMapping(ui.selectDirectoryButton_1, sourceID);
  mapper.setMapping(ui.selectDirectoryButton_2, 2);
  
  connect(ui.selectDirectoryButton_1, SIGNAL(clicked()), &mapper, SLOT(map()));
  connect(ui.selectDirectoryButton_2, SIGNAL(clicked()), &mapper, SLOT(map()));
  connect(&mapper, SIGNAL(mapped(int)), this, SLOT(selectFolder(int)));
//   selectFolder(1);
  
  connect(ui.compareButton, SIGNAL(clicked()), this, SLOT(compareFiles()));
  connect(ui.trashDirectoryButton, SIGNAL(clicked()), this, SLOT(changeTrashDirectory()));
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
  if(label->text() != "" )
    fillTreeWidget(i);
}

void MainWindow::changeTrashDirectory()
{
  qWarning() << "void MainWindow::changeTrashDirectory()";
  ui.trashDirectoryButton->setText(QFileDialog::getExistingDirectory());
  if(ui.trashDirectoryButton->text() == "")
    ui.trashDirectoryButton->setText("/tmp");
}

void MainWindow::compareFiles()
{
  qWarning() << "void MainWindow::compareFiles()";
  int count_1 = ui.treeWidget_1->topLevelItemCount();
  int count_2 = ui.treeWidget_2->topLevelItemCount();
  
  if(count_1 > 0 && count_2 > 0)
  {
    QList<QTreeWidgetItem *> twitems_1 = ui.treeWidget_1->selectedItems();
    QStringList stringlist1;
    for(QList<QTreeWidgetItem *>::const_iterator twitemsiterator = twitems_1.begin(); twitemsiterator != twitems_1.end(); ++ twitemsiterator)
    {
      stringlist1.append(ui.directoryLabel_1->text() + "/" + (*twitemsiterator)->text(0));
    }
    
//     qWarning() << stringlist1;
    
    QList<QTreeWidgetItem *> twitems_2 = ui.treeWidget_2->selectedItems();
    QStringList stringlist2;
    for(QList<QTreeWidgetItem *>::const_iterator twitemsiterator2 = twitems_2.begin(); twitemsiterator2 != twitems_2.end(); ++ twitemsiterator2)
    {
      stringlist2.append(ui.directoryLabel_2->text() + "/" + (*twitemsiterator2)->text(0));
    }
//     qWarning() << stringlist2;
    
    QStringList doubleFiles = compare(stringlist1, stringlist2);
    if(ui.actionComboBox->currentIndex() == 0)
    {
      QMessageBox::information(this, "Double Files", doubleFiles.join("\n"));
    }
    if(ui.actionComboBox->currentIndex() == 1)
    {
      // currentText == Move to:
      qWarning() << "Double Files to be moved:" << ui.actionComboBox->currentText() << doubleFiles;
      
    }
  }
}

void MainWindow::fillTreeWidget(int i)
{
  qWarning() << "void MainWindow::fillTreeWidget(int i)";
  QLabel *label;
  QTreeWidget *treeWidget;
  if(i == sourceID)
  {
    label = ui.directoryLabel_1;
    treeWidget = ui.treeWidget_1;
  }
  else
  {
    label = ui.directoryLabel_2;  
    treeWidget = ui.treeWidget_2;
  }
  treeWidget->clear();
  
  QDir dir (label->text());
  QStringList entryList = dir.entryList(QDir::AllEntries|QDir::NoDotAndDotDot);
  QStringList fileList = dir.entryList(QDir::Files);
  QString itstring;
  QTreeWidgetItem *item;
  foreach(itstring, entryList)
  {
    item = new QTreeWidgetItem(entryList.filter(itstring));
    if(!fileList.contains(itstring))
    {
      qWarning() << "Dir: " << itstring;
    }
    treeWidget->addTopLevelItem(item);
  }
}
