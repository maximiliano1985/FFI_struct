require "ffi"

module Layer
  extend FFI::Library
  ffi_lib "clib.so"
  
  class ToC < FFI::Struct
    layout :par1, :float,
           :par2, :float
  end # class
  
  class FromC < FFI::Struct
    layout :out1, :float,
           :out2, :float
  end # class
  
  attach_function :structure_to_C, [:pointer], :int
  attach_function :elapsed_time, [], :uint
  attach_function :structure_to_Ruby, [], :pointer
end # module

mp_ToC = FFI::MemoryPointer.new(Layer::ToC)
p_ToC  = Layer::ToC.new(mp_ToC)

p_ToC[:par1] = 1234.5
p_ToC[:par2] = 0.5
Layer::structure_to_C p_ToC

dT = Layer::elapsed_time
puts "Elapsed #{dT} seconds"

p_FromC = Layer::structure_to_Ruby