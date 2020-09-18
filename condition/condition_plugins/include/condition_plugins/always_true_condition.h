#ifndef TEST_CONDITIONS_ALWAYS_TRUE_CONDITION_H_INCLUDED
#define TEST_CONDITIONS_ALWAYS_TRUE_CONDITION_H_INCLUDED

#include <pluginlib/class_list_macros.h>

#include <scenario_conditions/condition_base.h>
#include <scenario_intersection/intersection_manager.h>
#include <scenario_utility/scenario_utility.h>

namespace test_conditions
{

class AlwaysTrueCondition
  : public scenario_conditions::ConditionBase
{
public:
  AlwaysTrueCondition();

  bool update(const std::shared_ptr<scenario_intersection::IntersectionManager> &) override;

  bool configure(YAML::Node node, std::shared_ptr<ScenarioAPI> api_ptr) override;
};

} // namespace test_conditions

#endif // TEST_CONDITIONS_ALWAYS_TRUE_CONDITION_H_INCLUDED

