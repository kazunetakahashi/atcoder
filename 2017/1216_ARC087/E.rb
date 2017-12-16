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
  ans = 0
  have = 0
  if !(tree.one.nil?)
    ans += cnt(tree.one)
    have += 1
  end
  if !(tree.zero.nil?)
    ans += cnt(tree.zero)
    have += 1
  end
  if have == 1
    ans += 1
  end
  return ans
end

ans = cnt(root)

puts "ans = #{ans}"

if ans%2 == 0
  puts "Bob"
else
  puts "Alice"
end
