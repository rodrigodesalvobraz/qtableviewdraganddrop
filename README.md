An minimal example of defining a model for QTableView with drag and drop in Qt 5.15 according to the [Qt's documentation](https://doc.qt.io/qt-5/model-view-programming.html#using-model-view-classes).

This currently works fine with one exception: when dragging a selection to the empty space below the last row, the program crashes. I would expect either for a new copy row to be inserted at the end of the table, or at least for nothing to happen. Why does the program crash?
