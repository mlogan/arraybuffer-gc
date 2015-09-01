
var recycle = require('./build/Release/array-buffer-recycler').recycle;
var create = require('./build/Release/array-buffer-recycler').create;
var buffer = new ArrayBuffer(1024 * 1024);

while (true) {
  // not expected to trigger gc because no new memory is being allocated.
  // Heap is not growing.
  buffer = recycle(buffer);

  // expected to trigger GCs because of allocation.
  //buffer = create();
}
