#if 0
/*��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ�� http://www.nowcoder.com/questionTerminal/9be0172896bd43948f8a32fb954e1be1*/

class Solution {
	priority_queue<int, vector<int>, less<int> > p;
	priority_queue<int, vector<int>, greater<int> > q;

public:
	void Insert(int num){
		if (p.empty() || num <= p.top()) p.push(num);
		else q.push(num);
		if (p.size() == q.size() + 2) q.push(p.top()), p.pop();
		if (p.size() + 1 == q.size()) p.push(q.top()), q.pop();
	}
	double GetMedian(){
		return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
	}
};


class Solution {
public:
	void Insert(int num) {
		data.push_back(num);
		std::sort(data.begin(), data.end());
	}

	double GetMedian() {
		unsigned int size = data.size();
		if (size & 1) {
			return data[size >> 1];
		}
		else {
			int left = data[(size >> 1) - 1];
			int right = data[size >> 1];
			return (static_cast<double>(left)+right) / 2;
		}
	}
private:
	vector<int> data;
};
#endif