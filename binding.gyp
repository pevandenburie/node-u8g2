{
  'targets': [
    {
      'target_name': 'nokia5110_kk1_binding',
      'defines': [ 'V8_DEPRECATION_WARNINGS=1' ],
      'sources': [ 'nokia5110/nokia5110_kk1.c', 'nokia5110/nokia5110_kk1_binding.cpp' ],
      'include_dirs': [ '<!(node -e "require(\'nan\')")' ],
      'libraries': [
              ]
    }
  ]
}
