class Tree
  attr_accessor :zero, :one

  def initialize()
    @zero = nil
    @one = nil
  end
end

n, l = gets.chomp.split(" ").map{|i| i.to_i}
s = []
n.times{
  s << gets.chomp
}

root = Tree.new()

s.each{|str|
  now = root
  str.chars{|c|
    if c == '0'
      if now.zero.nil?
        now.zero = Tree.new()
      end
      now = now.zero
    else
      if now.one.nil?
        now.one = Tree.new()
      end
      now = now.one
    end
  }
}

def cnt(tree)
  if tree.nil?
    return 0
  end
  zero = cnt(tree.zero)
  one = cnt(tree.one)
  if (zero == 0 && one == 0)
    return 1
  elsif (zero != 0 && one != 0)
    return (zero+1) ^ (one+1)
  elsif (zero != 0)
    return zero + 1
  else
    return one + 1
  end
end

ans = cnt(root)

puts "ans = #{ans}"

if ans == 0
  puts "Bob"
else
  puts "Alice"
end
