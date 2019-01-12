#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 1/12/2019, 9:02:39 PM
# Powered by Visual Studio Code
#

n = gets.to_i
a, b = gets.chomp.split(" ").map{|i| i.to_i}
q = gets.chomp.split(" ").map{|i| i.to_i}

cnt = Array.new(3){0}

q.each{|x|
  if x <= a
    cnt[0] += 1
  elsif x <= b
    cnt[1] += 1
  else
    cnt[2] += 1
  end
}

puts cnt.min


