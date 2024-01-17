project('timerscripts', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

deps = []

deps += dependency('libcurl', version: '>=8.5.0')
deps += dependency('rapidjson', version: '>=1.1.0')

exe = executable('timerscripts', ['src/main.c', 'src/api.c'],
  install : true, dependencies: deps)

###libruntime_lt_c=1
###libruntime_lt_r=0
###libruntime_lt_a=0
###libruntime_so_version = '@0@.@1@.@2@'.format((libruntime_lt_c - libruntime_lt_a),
###                                              libruntime_lt_a,
###                                              libruntime_lt_r)

###myLibrary = shared_library('timerscripts', ['src/main.c', 'src/api.c'],
###  version : libruntime_so_version,
###  dependencies: deps,
###  install : true)