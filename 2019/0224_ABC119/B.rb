#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 2/24/2019, 9:02:06 PM
# Powered by Visual Studio Code
#

n = gets.to_i

ans = 0.0

n.times{
  x, u = gets.chomp.split(" ")
  if u == "JPY"
    ans += x.to_f
  else
    ans += x.to_f * 380000.0
  end
}

puts sprintf("%.12", ans)
