{
  "targets": [
    {
      "target_name": "array-buffer-recycler",
      "sources": [
        "src/array-buffer-recycler.cc",
      ],
      "cflags_cc": [ "-std=c++11" ],
      'conditions': [
        [ 'OS=="mac"', {

          'xcode_settings': {
            'OTHER_CPLUSPLUSFLAGS' : ['-std=c++11', '-stdlib=libc++'],
            'MACOSX_DEPLOYMENT_TARGET': '10.7'
          },
        }],
      ],
    }
  ]
}
