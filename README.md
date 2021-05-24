An minimal example of defining a model for QTableView with drag and drop in Qt 5.15 according to the [Qt's documentation](https://doc.qt.io/qt-5/model-view-programming.html#using-model-view-classes).

Currently it is set to only move rows around a table. I find it a good example because it is a common use case, but still kind of tricky to get working. This [Qt Forums thread](https://forum.qt.io/topic/126692/reordering-rows-of-qtableview-with-drag-and-drop) has the whole story. The main issue is that it was hard to get rows *not* to overwrite destination rows, but to get inserted in their positions. A good way to get it working is by override `dropMimeData` to detect that case and change arguments to what they would be in the case of insertion.

I wanted to also leave the row selected after the dropping, but the code to do that apparently only works on Windows and Linux, and on the macOS it actually messes up where the row is dropped, so it is commented out here.
