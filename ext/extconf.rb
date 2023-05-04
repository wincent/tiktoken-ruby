#!/usr/bin/env ruby

require "mkmf"

$LDFLAGS << " -L../target/debug -l_tiktoken "

create_makefile("tiktoken")
