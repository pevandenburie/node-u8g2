{
  'targets': [
    {
      'target_name': 'u8g2_binding',
      'defines': [ 'V8_DEPRECATION_WARNINGS=1' ],
      'sources': [ 'u8g2/u8g2_ard_EDISON_t2.c' ],
      'libraries': [
        '-L/usr/local/lib', '-lU8g2lib'
      ]
    }
  ]
}
