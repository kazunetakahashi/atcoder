#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2019-5-25 21:02:10
# Powered by Visual Studio Code
#

r, d, x = gets.chomp.split(" ").map{|i| i.to_i}
for i in 0...10
  x = r * x - d
  puts x
end
