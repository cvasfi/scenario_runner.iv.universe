#ifndef SCENARIO_RUNNER_SCENARIO_RUNNER_H_INCLUDED
#define SCENARIO_RUNNER_SCENARIO_RUNNER_H_INCLUDED

#include <memory>

#include <rclcpp/rclcpp.hpp>

#include <scenario_expression/expression.h>
#include <scenario_intersection/intersection_manager.h>
#include <scenario_logger/logger.h>
#include <scenario_runner/scenario_terminater.h>
#include <scenario_sequence/sequence_manager.h>
#include <scenario_utility/scenario_utility.h>

namespace scenario_runner
{
class ScenarioRunner : public rclcpp::Node
{
public:
  ScenarioRunner();
  void run();

  double current_mileage() const
  {
    return simulator_->getMoveDistance();
  }

  simulation_is currently;

private:
  rclcpp::TimerBase::SharedPtr timer_;

  std::string scenario_path_;

  YAML::Node scenario_;

  const std::shared_ptr<ScenarioAPI> simulator_;

  scenario_expression::Context context;

  scenario_expression::Expression success, failure;

  std::shared_ptr<scenario_entities::EntityManager> entity_manager_;
  std::shared_ptr<scenario_sequence::SequenceManager> sequence_manager_;
  std::shared_ptr<scenario_intersection::IntersectionManager> intersection_manager_;

  void update();
};

}  // namespace scenario_runner

#endif  // SCENARIO_RUNNER_SCENARIO_RUNNER_H_INCLUDED
