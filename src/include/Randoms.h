#pragma once

#include <random>

template<class T> 
class Random final {
public:
	Random() = delete;
};

template<class T>
class SuperRandom {
public:
	using integer_rand = std::uniform_int_distribution<int32_t>;
	using double_rand  = std::uniform_real_distribution<double_t>;
	
	SuperRandom(T lower = T(), T upper = T()) 
		: lower_(lower)
		, upper_(upper)
		, randomNumber_(T())
		, engine_(std::random_device{}())
	{};

	virtual const T operator() () = 0;

	virtual const T	operator() (T lower, T upper) = 0;

	const T	Content() const {
		return randomNumber_;
	}

protected:
	T lower_;
	T upper_;
	T randomNumber_;
	std::default_random_engine	engine_;
};

template <>
class Random<int> final : public SuperRandom<int> {
public:
	Random(int lower = 0, int upper = 0) : SuperRandom(lower, upper) {}

public:
	virtual const int operator() () override {
		if ((lower_ || upper_) != 0) {
			integer_rand	dis{ lower_, upper_ };
			randomNumber_ = dis(engine_);
		}
		else
			randomNumber_ = engine_();

		return randomNumber_;
	}

	virtual const int operator() (int lower, int upper) override {
		integer_rand	dis{ lower, upper };
		randomNumber_ = dis(engine_);

		return	randomNumber_;
	}
};

template <>
class Random<double> final : public SuperRandom<double> {
public:
	Random(double lower = 0.0, double upper = 0.0) : SuperRandom(lower, upper) {}

public:
	virtual const double operator() () override {
		if ((lower_ || upper_) != 0.0) {
			double_rand		dis{ lower_, upper_ };
			randomNumber_ = dis(engine_);
		}
		else
			randomNumber_ = engine_();

		return randomNumber_;
	}

	virtual const double operator() (double lower, double upper) override {
		double_rand		dis{ lower, upper };
		randomNumber_ = dis(engine_);

		return	randomNumber_;
	}
};
