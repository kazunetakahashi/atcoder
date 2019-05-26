#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2019-5-26 21:03:02
# Powered by Visual Studio Code
#

n = gets.to_i
ary = []
for i in 1..n
  s, q = gets.chomp.split(" ").map{|x| x.to_s}
  q = q.to_i
  ary << [s, -q, i]
end
ary.sort.each{|s, q, i|
  puts i
}