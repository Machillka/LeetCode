#include <list>
#include <unordered_map>
#include <utility>

class LRUCache
{
  private:
    using Node = std::pair<int, int>;
    using List = std::list<Node>;
    using Iterator = List::iterator;

    static constexpr int INVALID_VALUE = -1;

  private:
    // 将已有节点移动到 MRU
    void Touch(Iterator it)
    {
        _visitOrder.splice(_visitOrder.end(), _visitOrder, it);
    }

    // 淘汰最久未使用节点
    void EvictLRU()
    {
        const int key = _visitOrder.front().first;

        _cached.erase(key);
        _visitOrder.pop_front();
    }

  public:
    explicit LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key)
    {
        auto it = _cached.find(key);

        if (it == _cached.end())
            return INVALID_VALUE;

        Iterator node = it->second;

        Touch(node);

        return node->second;
    }

    void put(int key, int value)
    {
        auto it = _cached.find(key);

        // key 已存在
        if (it != _cached.end())
        {
            Iterator node = it->second;

            node->second = value;
            Touch(node);

            return;
        }

        // 插入新的 MRU 节点
        _visitOrder.emplace_back(key, value);

        Iterator node = std::prev(_visitOrder.end());
        _cached.emplace(key, node);

        // 超出容量，淘汰 LRU
        if (_visitOrder.size() > static_cast<std::size_t>(_capacity))
        {
            EvictLRU();
        }
    }

  private:
    int _capacity;

    // front = LRU
    // back  = MRU
    List _visitOrder;

    // key -> list node
    std::unordered_map<int, Iterator> _cached;
};