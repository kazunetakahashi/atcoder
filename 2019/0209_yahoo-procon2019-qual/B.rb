#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2/9/2019, 9:03:35 PM
# Powered by Visual Studio Code
#

ary = Array.new(4){0}
3.times{
  a, b = gets.chomp.split(" ").map{|i| i.to_i}
  a -= 1
  b -= 1
  ary[a] += 1
  ary[b] += 1
}
if ary.max == 3
  puts "NO"
else
  puts "YES"
end