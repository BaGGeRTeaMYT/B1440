#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>
#include <unordered_set>

struct Segment {
  int x, y;

  bool operator<(const Segment& other) const {
    if (this->x == other.x) {
      return this->y < other.y;
    }
    return this->x < other.x;
  }
  bool operator==(const Segment& other) const {
    return this->x == other.x && this->y == other.y;
  }
  friend std::istream& operator>>(std::istream& istream, Segment& obj) {
    istream >> obj.x >> obj.y;
    return istream;
  }
  friend std::ostream& operator<<(std::ostream& ostream, const Segment& obj) {
    ostream << obj.x << ' ' << obj.y;
    return ostream;
  }
};

struct Point {
  int segment_id;
  int coord;
  enum {
    BEGIN,
    END
  } state;

  bool operator<(const Point& other) const {
    if (this->coord == other.coord) {
      if (this->state == other.state) {
        return this->segment_id < other.segment_id;
      }
      return this->state == Point::BEGIN;
    }
    return this->coord < other.coord;
  }
};

int main() {
  int n;
  std::cin >> n;

  std::vector<Segment> segments(n);
  std::set<Point> points;
  int segment_id = 0;
  for (auto& segment : segments) {
    std::cin >> segment;
    points.insert({ segment_id, segment.x, Point::BEGIN });
    points.insert({ segment_id++, segment.y, Point::END });
  }

  std::unordered_set<int> important_segments;
  std::unordered_set<int> processed_segments;
  long long answer = 0;
  for (const auto& point : points) {
    if (processed_segments.find(point.segment_id) == processed_segments.end()) {
      if (point.state == Point::BEGIN) {
        important_segments.insert(point.segment_id);
      } else {
        answer++;
        for (const auto& seg_id : important_segments) {
          processed_segments.insert(seg_id);
        }
        important_segments.clear();
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}