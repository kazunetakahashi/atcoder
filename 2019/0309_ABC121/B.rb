#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 3/9/2019, 9:02:02 PM
# Powered by Visual Studio Code
#

n, m, c = gets.chomp.split(" ").map{|i| i.to_i}
b = gets.chomp.split(" ").map{|i| i.to_i}
a = []
n.times{
  a << gets.chomp.split(" ").map{|i| i.to_i}
}
ans = 0
for i in 0...n
  t = c
  for j in 0...m
    t += a[i][j] * b[j]
  end
  if t > 0
    ans += 1
  end
end

puts ans
