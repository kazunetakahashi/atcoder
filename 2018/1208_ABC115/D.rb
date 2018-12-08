#
# File    : D.rb
# Author  : Kazune Takahashi
# Created : 12/8/2018, 9:19:27 PM
# Powered by Visual Studio Code
#

n, x = gets.chomp.split(" ").map{|i| i.to_i}

@l = Array.new(51)
@q = Array.new(51)

@l[0] = 1
@q[0] = 1

for i in 1...51
  @l[i] = 3 + 2 * @l[i - 1]
  @q[i] = 1 + 2 * @q[i - 1]
end

def calc(y, k)
  if k == 0
    return y
  end
  if y <= 1
    return 0
  elsif y <= @l[k] / 2
    return calc(y - 1, k - 1)
  elsif y == @l[k] / 2 + 1
    return @q[k - 1] + 1
  elsif y <= @l[k] - 1
    return @q[k - 1] + 1 + calc(y - @l[k]/2 - 1, k - 1)
  else
    return 2 * @q[k - 1] + 1
  end
end

puts calc(n, x)
