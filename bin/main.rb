#!/usr/bin/env ruby
#************************************************************
# 
# Program:      FFI_struct
# 
# File:         main.rb
# 
# Description:  Simple examples of FFI library implementation
# 
# Author:       Carlos Maximiliano Giorgio Bort (cmgb)
# 
# Environment:  ruby 1.9.2p290 (2011-07-09 revision 32553)
#              x86_64-darwin10.8.0
#              
# Notes:        Copyright (c) 2012 University of Trento.
#              All rights reserved.
# 
# Revisions:    1.00  02/08/12 (cmgb) First release
# 
#************************************************************

require "ffi"

SIZE_OF_ARRAY = 10

# Collection of C structures and functions
# @author cmgb
module Layer
  extend FFI::Library
  ffi_lib "../ext/src/clib.so"
  
  # Structure whose values are defined in Ruby and read in C 
  # @author cmgb
  class ToC < FFI::Struct
    layout :par1, :float,
           :par2, :float
  end # class
  
  # Structure whose values are defined in C and read in Ruby 
  # @author cmgb
  class FromC < FFI::Struct
    layout :out1, :float,
           :out2, :float
  end # class
  
  # Structure whose string is defined in C and read in Ruby 
  # @author cmgb
  class MyArray_t < FFI::Struct
    layout :Value, :uint8,
           :String, [:uint8, SIZE_OF_ARRAY]
  end # class
  
  # include the C functions
  attach_function :structure_to_C, [:pointer], :void
  attach_function :elapsed_time, [], :uint
  attach_function :structure_to_Ruby, [:pointer], :pointer
  attach_function :put_structure_to_Ruby, [:pointer], :void
end # module

# Some examples
# @author cmgb
#================================================================

# Send data to C structure
mp_ToC = FFI::MemoryPointer.new(Layer::ToC)
p_ToC  = Layer::ToC.new(mp_ToC)
p_ToC[:par1] = 1234.5
p_ToC[:par2] = 0.5
Layer::structure_to_C(p_ToC)

#================================================================

# Read float from C function
dT = Layer::elapsed_time
puts "Elapsed #{dT} seconds"

# Read structure from C
p_FC = FFI::MemoryPointer.new(:pointer)
p_FromC = Layer::structure_to_Ruby(p_FC)
Layer::put_structure_to_Ruby(p_FromC)

#================================================================

# Read string from C
# by value
mas = Layer::MyArray_t.new
mas[:String].to_ptr.put_string(0,"U R a")
p mas[:String].to_ptr.read_string

# by pointer
mpmas = FFI::MemoryPointer.new(Layer::MyArray_t)
pmas = Layer::MyArray_t.new(mpmas)
p pmas[:String] = "foo"
