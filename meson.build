project('mhlight', 'c')

cc = meson.get_compiler('c')

m_dep = cc.find_library('m', required : false)
thread_dep = dependency('threads')


sources = [
  'bspfile.c',
  'cmdlib.c',
  'colour.c',
  'entities.c',
  'light.c',
  'litfile.c',
  'ltface.c',
  'mathlib.c',
  'threads.c',
  'trace.c',
  'trilib.c'
]

executable('mhlight', sources, dependencies: [thread_dep, m_dep])
