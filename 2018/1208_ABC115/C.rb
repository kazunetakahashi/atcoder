#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 12/8/2018, 9:13:23 PM
# Powered by Visual Studio Code
#

n, k = gets.chomp.split(" ").map{|i| i.to_i}
h = []
n.times{
  h << gets.to_i
}
h.sort!
ans = h[k - 1] - h[0]
for i in 0..n - k
  ans = [ans, h[k - 1 + i] - h[i]].min
end
puts ans
