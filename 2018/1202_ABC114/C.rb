#
# File    : C.rb
# Author  : Kazune Takahashi
# Created : 2018-12-2 21:03:42
# Powered by Visual Studio Code
#

n = gets.to_i

ary = Array.new(11){[]}
ary[0] = ['7', '5', '3']

10.times{|t|
  ary[t].each{|x|
    ary[t+1] << x + '7'
    ary[t+1] << x + '5'
    ary[t+1] << x + '3'
  }
}

ans = []
11.times{|t|
  ans.concat(ary[t])
}

res = 0

ans.each{|str|
  if !(str.include?('3') && str.include?('5') && str.include?('7'))
    next
  end
  if str.to_i <= n
    res += 1
  end
}

puts res