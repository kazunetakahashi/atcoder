#
# File    : D.rb
# Author  : Kazune Takahashi
# Created : 12/22/2018, 9:07:35 PM
# Powered by Visual Studio Code
#

n = gets.to_i
a = []
n.times{
  a << gets.to_i
}
a.each{|num|
  if num % 2 == 1
    puts "first"
    exit
  end
}
puts "second"