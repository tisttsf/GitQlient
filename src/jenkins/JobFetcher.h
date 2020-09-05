#pragma once

#include <IFetcher.h>
#include <JenkinsJobInfo.h>

namespace Jenkins
{

class JobFetcher final : public IFetcher
{
   Q_OBJECT

signals:
   void signalJobsReceived(const QVector<JenkinsJobInfo> &jobs);

public:
   explicit JobFetcher(const IFetcher::Config &config, const QString &jobUrl, QObject *parent = nullptr);

   void triggerFetch() override;

private:
   QString mJobUrl;
   QVector<JenkinsJobInfo> mJobs;
   int mJobsToUpdated = 0;

   void processData(const QJsonDocument &json) override;
   void updateJobs(const JenkinsJobInfo &updatedInfo);
};
}