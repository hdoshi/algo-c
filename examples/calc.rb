#!/usr/bin/env ruby

#("1+4+5*12/4").split("+").map{ |x| x.split("*") }.map{ |x| x.map { |y| y.split("/").map {|z| z.to_i}.reduce(:/) }.reduce(:*) }.reduce(:+)

x = "5+21+5*12/4"
res =
x.split("+").map {
  |x| x.split("*").map {
    |x| x.split("/").map {
      |x| x.to_i
    }.reduce(:/)
  }.reduce(:*)
}.reduce(:+)

puts res;
