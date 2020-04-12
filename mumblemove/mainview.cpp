// MumbleMove
//
// Copyright (C) 2020  Thomas Axelsson
//
// This file is part of MumbleMove.
//
// MumbleMove is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// MumbleMove is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with MumbleMove.  If not, see <https://www.gnu.org/licenses/>.
//

#include "mainview.h"

#include <QDebug>
#include <QMouseEvent>

MainView::MainView() {
    setCursor(defaultCursor);
}

void MainView::contextMenuEvent(QContextMenuEvent *event) {
    emit contextMenu(event);
}

void MainView::mouseMoveEvent(QMouseEvent *event) {
    if (dragging) {
        emit moveWindow(event->globalX() - dragStart.x(), event->globalY() - dragStart.y());
    } else {
        // Propagate the event to the children
        QGraphicsView::mouseMoveEvent(event);
    }
}

void MainView::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && event->modifiers() == Qt::ControlModifier) {
        dragStart = event->pos() + pos();
        dragging = true;
        setCursor(Qt::SizeHorCursor);
    } else {
        // Propagate the event to the children
        QGraphicsView::mousePressEvent(event);
    }
}

void MainView::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragging = false;
        setCursor(defaultCursor);
    }

    // Propagate the event to the children
    QGraphicsView::mouseReleaseEvent(event);
}
