#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2018-10-6 21:02:02
# Powered by Visual Studio Code
#

n, t = gets.chomp.split(" ").map{|i| i.to_i}
ans = 1000000
n.times{
  c, t = gets.chomp.split(" ").map{|i| i.to_i}
  if t <= T
    ans = [ans, c].min
  end
}
if ans == 1000000
  puts "TLE"
else
  puts ans
end