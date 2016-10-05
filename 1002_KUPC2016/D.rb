class Kokuban

  attr_accessor :ary

  def add_column(b, num)
    tmp = Marshal.load(Marshal.dump(ary))
    if (b)
      # puts tmp
      tmp << num
    else
      tmp.unshift(num)
    end
    return tmp
  end

  def Kokuban.flush(ary)
    ans = [[], []]
    ary.each{ |x|
      if x == 0
        ans[0] << '.'
        ans[1] << '.'
      elsif x == 1
        ans[0] << '.'
        ans[1] << '#'
      elsif x == 2
        ans[0] << '#'
        ans[1] << '.'
      else
        ans[0] << '#'
        ans[1] << '#'
      end
    }
    puts ans[0].join("")
    puts ans[1].join("")
    STDOUT.flush
  end
  
end

n = gets.to_i
kokuban = Kokuban.new
kokuban.ary = []

bol = false

while true
  added = false
  for i in 0..3
    tmp = kokuban.add_column(bol, i)
    Kokuban.flush(tmp)
    r = gets.chomp
    if r == "end"
      exit
    elsif r == 'T'
      kokuban.ary = tmp
      added = true
      break
    else
      #
    end
  end
  if added
    #
  else
    # puts "next state"
    bol = true
  end
end
