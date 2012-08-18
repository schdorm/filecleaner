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

#include "compare.h"
#include <QtCore/QHash>
#include <QtCore/QFile>
#include <math.h>
#include <stdlib.h>

#include <QtCore/QtDebug>


quint64 hexToDec(const QByteArray &hex)
{
  quint64 result = 0; quint64 position = 0;
  char atPos;
  for(quint64 i=hex.size(); i; i--)
  {
    atPos = hex.at(i-1);
    switch(atPos)
    {
      case '0':
	break;
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':	
      {
	result+=pow(16,position)* atoi(&atPos);
	break;
      }
      case 'A':
      case 'a':
      {
	result += pow(16,position)* 10;
	break;
      }
      case 'B':
      case 'b':
      {
	result += pow(16,position)* 11;
	break;
      }
      case 'C':
      case 'c':
      {
	result += pow(16,position)* 12;
	break;
      }
      case 'D':
      case 'd':
      {
	result += pow(16,position)* 13;
	break;
      }
      case 'E':
      case 'e':
      {
	result += pow(16,position)* 14;
	break;
      }
      case 'F':
      case 'f':
      {
	result += pow(16,position)* 15;
	break;
      }
      default:
	return 0;
    }
    position++;
  }
  return result;
}



QStringList compare(const QStringList &list1, const QStringList &list2 )
{
  qWarning() << "QStringList compare(const QStringList &list1, const QStringList &list2 )";
  QStringList doubleFiles;
  QHash <uint, QString> HashTable1;
  QHash <uint, QString> HashTable2;
  QStringList::const_iterator stringlistiterator;
  for(stringlistiterator = list1.begin(); stringlistiterator != list1.end(); ++ stringlistiterator )
  {
    QFile file(*stringlistiterator);
    if(file.open(QIODevice::ReadOnly))
      HashTable1.insert(qHash(file.readAll()), *stringlistiterator);
  }
  for(stringlistiterator = list2.begin(); stringlistiterator != list2.end(); ++ stringlistiterator )
  {
    QFile file(*stringlistiterator);
    if(file.open(QIODevice::ReadOnly))
      if(HashTable1.contains(HashTable2.insert(qHash(file.readAll()), *stringlistiterator).key()))
      {
	doubleFiles << *stringlistiterator;
      }
  }
  
  QHash <uint, QString>::const_iterator it;
  for(it = HashTable1.constBegin(); it != HashTable1.constEnd(); it++)
    qWarning() << it.key() << it.value();
  qWarning() << "Table 2:";
  for(it = HashTable2.constBegin(); it != HashTable2.constEnd(); it++)
    qWarning() << it.key() << it.value();
  qWarning() << "End: compare ( ... )";
  return doubleFiles;
}
