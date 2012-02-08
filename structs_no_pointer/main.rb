require 'ffi'

# to pass the struct to ruby
# http://stackoverflow.com/questions/8982393/how-to-wrap-function-in-ruby-ffi-method-that-takes-struct-as-argument/8990201#8990201

module DoitLib
  extend FFI::Library
  ffi_lib "layer_c.so"

  class What < FFI::Struct
    layout :address, :uint,
           :override, :float,
           #:something, :pointer
  end

  attach_function 'scan_struct', [What.by_value],:void

end

mywhat = DoitLib::What.new
mywhat[:address] = 1234
mywhat[:override] = 0.5
DoitLib.scan_struct(mywhat)