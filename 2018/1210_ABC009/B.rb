#
# File    : B.rb
# Author  : Kazune Takahashi
# Created : 12/10/2018, 10:41:05 PM
# Powered by Visual Studio Code
#

n = gets.to_i
hash = {}
n.times{
  a = gets.to_i
  if !hash.has_key?(a)
    hash[a] = 1
  end
}
puts hash.keys.sort[-2]