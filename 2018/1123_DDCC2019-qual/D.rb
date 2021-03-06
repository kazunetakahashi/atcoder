#
# File    : D.rb
# Author  : Kazune Takahashi
# Created : 11/24/2018, 8:41:06 AM
# Powered by Visual Studio Code
#

require 'prime'

class Solve

  L = 31
  MAXI = 10 ** 12
  attr_accessor :a, :primes, :m, :x, :ans

  def initialize()
    @a = Array.new(L)
    for i in 2...L
      @a[i] = gets.to_i
    end
    @primes = {}
    for i in 2...L do
      if Prime.prime?(i - 1)
        @primes[i - 1] = @a[i] % (i - 1)
      end
    end
    # STDERR.puts primes.inspect
    @m = 1
    @x = 0
    @ans = nil
  end

  def Solve.sum(y, q)
    ans = 0
    while y > 0
      ans += y % q
      y /= q
    end
    return ans
  end

  def check(y)
    for i in 2...L
=begin
      if y == 25
        puts "Solve.sum(#{y}, #{i}) = #{Solve.sum(y, i)}, a[#{i}] = #{a[i]}"
      end
=end
      if Solve.sum(y, i) != a[i]
        return false
      end
    end
    return true
  end

  def Solve.power(y, i, q)
    _power(y % q, i, q)
  end

  def Solve._power(y, i, q)
    if i == 0
      return 1
    elsif i % 2 == 1
      return (_power(y, i - 1, q) * y) % q
        else
      half = _power(y, i / 2, q)
      return (half ** 2) % q
    end
  end

  def Solve.inv(y, q)
    raise unless Prime.prime?(q)
    power(y, q - 2, q)
  end

  def calc_x()
    primes.each{|q, b|
      # STDERR.puts "q = #{q}, b = #{b}"
      # STDERR.puts "Solve.inv(#{m % q}, #{q}) = #{Solve.inv(m, q)}"
      t = ((b + q - x % q) * Solve.inv(m, q)) % q
      @x += m * t
      @m *= q
    }
  end

  def solve()
    calc_x()
    n = x
    # STDERR.puts "n = #{n}"
    while n <= MAXI
      # STDERR.puts "n = #{n}"
      if check(n)
        @ans = n
        return
      end
      n += m
    end
    @ans = nil
  end

end

solver = Solve.new()
solver.solve()
if solver.ans.nil?
  puts "invalid"
else
  puts solver.ans
end