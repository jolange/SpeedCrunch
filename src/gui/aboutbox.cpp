//  This file is part of the SpeedCrunch project
//  Copyright (C) 2004, 2006 Ariya Hidayat <ariya@kde.org>
//  Copyright (C) 2005, 2006 Johan Thelin <e8johan@gmail.com>
//  Copyright (C) 2007, 2009, 2013 Helder Correia <helder.pereira.correia@gmail.com>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; see the file COPYING.  If not, write to
//  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
//  Boston, MA 02110-1301, USA.

#include "gui/aboutbox.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QTextEdit>
#include <QVBoxLayout>

#define THANKS(name) #name"<br>"

AboutBox::AboutBox(QWidget* parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    setObjectName("AboutBox");
    setWindowTitle(tr("About SpeedCrunch"));

    QString msg = "<center>";
    msg += "<img src=\":/speedcrunch.png\"><br>";
    msg += "<b>SpeedCrunch " SPEEDCRUNCH_VERSION;
#ifdef SPEEDCRUNCH_PORTABLE
    msg += " (Portable Edition)";
#endif
    msg += "</b><br>(Qt " + QLatin1String(QT_VERSION_STR) + ")<br>";

    const QString authors = "<p><b>%2</b><br>%1";
    msg += authors.arg(tr("Maintainer, core developer, designer, translator")).arg("Helder Correia");
    msg += authors.arg(tr("Original author")).arg("Ariya Hidayat");
    msg += authors.arg(tr("Math engine")).arg("Wolf Lammen");
    msg += authors.arg(tr("Packager")).arg("Alessandro Portale");
    msg += authors.arg(tr("Former maintainer")).arg("Johan Thelin");

    msg += "<p>" + QString("<b>%1</b><br>").arg(tr("Thanks"));
    msg +=
        THANKS(Alan Davies)
        THANKS(Alejandro Villarreal)
        THANKS(Alexey Kouznetsov)
        THANKS(Anders Lund)
        THANKS(Andreas Scherer)
        THANKS(Artem Golovinsky)
        THANKS(Aur&eacute;lien G&acirc;teau)
        THANKS(Bart Martens)
        THANKS(Bernhard Schiffner)
        THANKS(Christian Ehrlich)
        THANKS(Damir Perisa)
        THANKS(Daniel Sch&auml;ufele)
        THANKS(Derek O’Connor)
        THANKS(Enrico R&oacute;s)
        THANKS(Eugeniu Plamadeala)
        THANKS(Felix Krull)
        THANKS(F Chris Carrera)
        THANKS(Francesco di Cugno)
        THANKS(Gary Cramblitt)
        THANKS(Henrik Nordstrom)
        THANKS(Henrique Pinto)
        THANKS(James Yuzwalk)
        THANKS(Jean-Remy Falleri)
        THANKS(Johannes Lange)
        THANKS(Jonathan Avraham)
        THANKS(Jonathan Riddell)
        THANKS(Lars Ivar Igesund)
        THANKS(Maciek Borowka)
        THANKS(Marco Wegner)
        THANKS(Matthew J Smith)
        THANKS(Melchior Franz)
        THANKS(Michael Pyne)
        THANKS(Mohamed Eldesoky)
        THANKS(Oliver Gubler)
        THANKS(Petri Damst&eacute;n)
        THANKS(Philippe Fremy)
        THANKS(Pieter Pareit)
        THANKS(Roberto Alsina)
        THANKS(Roland ’liquidat’ Wolters)
        THANKS(Sarah Hobbs)
        THANKS(S&eacute;bastien Szymanski)
        THANKS(Stephan Binner)
        THANKS(Steven Honeyman)
        THANKS(Tey)
        THANKS(Thomas Luebking)
        THANKS(Thomas Nagy)
        THANKS(Vibet Alexis)
        THANKS(Vladimir Pouzanov)
        THANKS(Wictor Lund)
        THANKS(Witold Wysota)
        THANKS(1100101)
        ;

    msg += "</p><p>";

    msg += "<p><b>";
    msg += tr("Copyright (C) 2004-2015 The SpeedCrunch developers");
    msg += "</b></p>";

    msg += "<p>";
    msg += tr("This program is free software; you can redistribute it and/or "
              "modify it under the terms of the GNU General Public License "
              "as published by the Free Software Foundation; either version 2 "
              "of the License, or (at your option) any later version");
    msg += "</p>";
    msg += "<p>";
    msg += tr("This program is distributed in the hope that it will be useful, "
              "but WITHOUT ANY WARRANTY; without even the implied warranty of "
              "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the "
              "GNU General Public License for more details.");
    msg += "</p>";

    msg += "</center>";

    QTextEdit* textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    textEdit->setText(msg);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(textEdit);

    setWindowTitle(tr("About SpeedCrunch"));
}
